
x = gets.chomp!.split("").map(&:to_s)


stack = []

x.length.times do |i|
	if x[i]=="S"
		stack.push(x[i])
	elsif x[i]=="T"&&(stack.last=="T"||stack.empty?)
		stack.push(x[i])
	else
		stack.pop
	end
end

puts stack.length



