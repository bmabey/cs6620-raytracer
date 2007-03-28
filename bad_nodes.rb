#!/usr/bin/env ruby
#
#  Created by Ben Mabey on 2007-03-27.
#  Copyright (c) 2007. All rights reserved.

1.upto(30) do |i| 
  puts "bad node: #{i}" unless `ssh lab4-#{i} ls`["cs6620"]
end