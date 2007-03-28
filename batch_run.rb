#!/usr/bin/env ruby
#
#  Created by Ben Mabey on 2007-03-27.
#  Copyright (c) 2007. All rights reserved.


class Node
  
  attr_reader :output
  def initialize(name, daemon)
    @name = name
    @daemon = daemon
    @output=[]
  end
  
  def run
    job = @daemon.get_job
    while !job.nil?
      puts "Starting ssh #{@name} #{job}"
      @output << parse_output(`ssh #{@name} #{job}`)
      job = @daemon.get_job
    end
  end
  
  private
  def parse_output(output)
    o = output.split("\n")
    {:render_time => o[3].split(" ")[-1].to_f, :start_line => o[1].split("-")[0].to_i, :lines => o.slice(4,o.size)}
  end
  
end

class JobDaemon
  attr_reader :nodes
  attr_reader :jobs
  def initialize(bad_nodes, resolution, step, output_name) 
    @nodes = []
    @jobs = []
    @step = step
    @output_name = output_name
    @resolution = resolution
    base_job_command = "\"cd ~/cs6620/Raytracer/Raytracer/ && nice ./raytracer #{resolution} START_LINE #{step}\" "
    @steps = resolution / step
    @steps.times {|i| @jobs << base_job_command.sub("START_LINE", (i*step).to_s)}

    1.upto(30) { |i| @nodes << Node.new("lab4-#{i}", self) unless bad_nodes.detect{|n| n == i} }
  end
  
  def get_job
    @jobs.pop
  end
  
  def run
    start_time = Time.now
    node_threads = []
    @nodes.each do |node|
     node_threads << Thread.new(node) do |n|
       n.run
     end
    end
    node_threads.each{|t| t.join}
    
    cluster_time = Time.now - start_time
    #Collect all the output and sort by line number
    all_output = @nodes.inject([]) { |m,node| m = m + node.output}
    if all_output.size != @steps
      puts "Error!  There should be #{@steps} outputs, but we only got #{all_output.size}!"
      exit
    end
    all_output = all_output.sort_by{|output| 1-output[:start_line]}
    all_output.each{|o| puts "Line: ##{o[:start_line]}"}
    wall_time = all_output.inject(0.0){|m,o| m = m + o[:render_time]}
    #Send it to a PPM
    out_file = File.new("#{@output_name}.ppm","w")
    out_file << "P3\n" << @resolution << " " << @resolution << "\n" << "255\n"
    all_output.each do |output|
      output[:lines].each do |line| 
        out_file << line 
        out_file << "\n"
      end
    end
    out_file.close
    #Now convert it to a PNG using imagemagick
    puts "Cluster Render Time: #{cluster_time}"
    puts "Wall time: #{wall_time}"
    puts "Converting #{@output_name}.ppm to #{@output_name}.png..."
    puts `convert #{@output_name}.ppm #{@output_name}.png`
    
  end
  
end

daemon =JobDaemon.new([1,6,22,23], 1024, 4, "dominoes_jittered81_cubicsplinefilter")
daemon.run
