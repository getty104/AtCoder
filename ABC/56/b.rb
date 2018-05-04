

w, a, b = gets.split.map(&:to_i)

if (a - b).abs <= w
	puts 0
else
	if b > a+w
		puts (b-a-w).abs
	else
		puts (a-b-w).abs
	end
end