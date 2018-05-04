require 'prime'
include Math
define_method :max, 		-> (a,b) { a > b ? a : b }
define_method :min, 		-> (a,b) { a < b ?  a : b }
define_method :swap, 		-> (a,b) { a, b = b, a }
define_method :gi, 			-> () { gets.split.map(&:to_i) }
define_method :gs, 			-> () { gets.chomp }
define_method :getc,		-> () { gets.chomp.split('') }
define_method :fi, 			-> () {first}
define_method :darray,	-> (size1, size2, init = nil) { Array.new(size1){Array.new(size2){init}} }
define_method :array,		-> (size,init = nil) { Array.new(size){init} }
define_method :putall, 	-> (obj) { obj.each { |o| puts o } }
define_method :repl, 		-> (st,en, &block) { st.upto en do |i| block.call(i) end }
define_method :rep, 		-> (num, &block) { num.times do |i| block.call(i) end }

		prime = array(1001,1)
		n = gi[0]
		repl 2, n do |m|
			m.prime_division.each {|x| 
				prime[x[0]] += x[1]
			}
		end
		ans = 1
		repl 2, 1000 do |i|
			ans *= prime[i]
			ans %= (10 ** 9) + 7
		end

		puts ans

