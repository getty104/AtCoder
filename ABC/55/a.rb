include Math
define_method :max, -> (a,b) { a > b ? a : b }
define_method :min, -> (a,b) { a < b ?  a : b }
define_method :swap, -> (a,b) { a, b = b, a }
define_method :rep, -> (num, &block) { num.times do |i| block.call(i) end }
define_method :repl, -> (st,en, &block) { st.upto en-1 do |i| block.call(i) end }
define_method :array, -> (size,init = nil) { Array.new(size){init} }
define_method :darray, -> (size1, size2, init = nil) { Array.new(size1){Array.new(size2){init}} }
define_method :gi, -> () { gets.split.map(&:to_i) }
define_method :gs, -> () { gets.chomp }
define_method :putall, -> (obj) { obj.each do |o| puts o end }


n = gi[0]

ans = n*800-200*(n/15)

puts ans