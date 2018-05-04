require 'fileutils'

dirs = Dir.glob("*")

dirs.each do |dir|
  FileUtils.mv(dir,dir.split("-")[1])
end
