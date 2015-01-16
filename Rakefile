# Desc: Rakefile for c++ projects
##################################

# the final executable file name:
FINAL = %w[bin/main.exe]

# compiler options:
CC   = "g++ -Wall"
INCS = "-Iinclude"
OPTS = "-std=c++0x -g"      # <- (-g= debug symbols), (c++0x= regex support)
LIBS = ""

# file lists:
EXE = FileList['bin/*.exe']
SRC = FileList['src/*.cpp']
OBJ = SRC.ext('o')              # <- SRC basenames with .o extensions

# directory lists:
DIRS = %w/src include bin/
DIRS.each { |dir| directory dir }

# require setup before working on SRC files:
SRC.each { |f| file f => :setup }

####################################
# Tasks:
####################################

# TASK: setup:
desc "Create directories: #{DIRS.join(', ')}"
task :setup => DIRS

# TASK: default:
desc "Compile #{FINAL.join(', ')}"
task :default => :run

# TASK: com;ile
desc "Compile #{FINAL.join(', ')}"
task :compile => FINAL

# TASK: run:
desc "Compile and run #{FINAL.join(', ')}"
task :run => OBJ + FINAL do
  FINAL.each { |exe| sh exe }
end

# TASK: debug:
desc "Debug #{FINAL[0]}"
task :debug => OBJ + FINAL do
  sh "gdb #{FINAL[0]}"
end

# TASK: clean:
desc "Remove all src/*.o and bin/*.exe files"
task :clean do
  OBJ.each { |obj| sh "rm -f #{obj}" if File.exist?(obj) }
  EXE.each { |exe| sh "rm -f #{exe}" if File.exist?(exe) }
  sh "rm -f *.log"
end

# TASK: addclass:
desc "Creates a new c++ class (.h & .cpp files) with the given NAME rake variable."
task :addclass, [:name] => [:setup] do |task, args|
  approot   = File.expand_path(File.dirname(__FILE__))
  classname = args[:name]
  header    = File.join(approot, "include", "#{classname}.h")
  source    = File.join(approot, "src", "#{classname}.cpp")
  puts "class:   #{classname}"
  puts "header:  #{header}"
  puts "source:  #{source}"

  tab = " "*4;

  File.open(header, 'w') do |hfile|
    hfile.puts "\n#ifndef #{classname}_h\n#define #{classname}_h\n\n"
    hfile.puts "class #{classname} {\npublic:\n"
    hfile.puts "#{tab}#{classname}();\n#{tab}~#{classname}();\n";
    hfile.puts "protected:\n};\n\n#endif\n\n"
  end

  File.open(source, 'w') do |sfile|
    sfile.puts "\n#include \"#{classname}.h\"\n\n"
    sfile.puts "#{classname}::#{classname}() {\n}\n\n"
    sfile.puts "#{classname}::~#{classname}() {\n}\n\n"
  end

end

########################################################################
## Rules:
########################################################################

# RULE: how to create .o files (compile matching .cpp file):
rule '.o' => '.cpp' do |t|
  sh "#{CC} #{INCS} #{t.source} -c -o #{t.name} #{OPTS} #{LIBS}"
end

# RULE: how to create .exe files (compile all .o files):
rule '.exe' => OBJ do |t|
  sh "#{CC} #{INCS} #{OBJ} -o #{t.name} #{OPTS} #{LIBS}"
end

