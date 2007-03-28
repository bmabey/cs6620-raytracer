#!/usr/bin/env ruby
#
#  Created by Ben Mabey on 2007-03-27.
#  Copyright (c) 2007. All rights reserved.

class Foo
  
def good_node?(host_name)
  p_ssh = IO.popen("ssh #{host_name} ls")
  good = false
  begin
    unless IO.select([p_ssh], nil, nil, 5).first.empty?
      good = true if p_ssh.readlines.join()["cs6620"]
    end
  rescue
    good = false
  end
  good
end

end


f = Foo.new
1.upto(48) do |i| 
  puts ( (f.good_node?("lab1-#{i}")) ? "good " : "bad ") + "node: lab1-#{i}"
end

1.upto(30) do |i| 
  puts ( (f.good_node?("lab4-#{i}")) ? "good " : "bad ") + "node: lab4-#{i}"
end