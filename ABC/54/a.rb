n = gets.split.map(&:to_i)

if n[0] > n[1] && n[1] != 1 
	puts "Alice"
elsif n[0] < n[1] && n[0] != 1
	puts "Bob"
elsif n[0] == n[1]
	puts "Draw"
elsif n[0] == 1
	puts "Alice"
elsif n[1] == 1
	puts "Bob"
end