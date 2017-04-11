
n = gets.split.map(&:to_i)
a = []
b = []
n[0].times do
	a << gets.chomp!.split('').map(&:to_s)
end

n[1].times do
	b << gets.chomp!.split('').map(&:to_s)
end

ans = false
(n[0] - n[1] + 1).times do |i|
	(n[0] - n[1] + 1).times do |l|
		dt = true
		n[1].times do |j|
			n[1].times do |k|
				if	b[j][k] != a[j + i][k + l]
					dt = false
				end
			end
		end
		if dt
			ans = true
			break
		end
	end
	if ans
		break 
	end
end

if ans 
	puts "Yes"
else
	puts "No"
end