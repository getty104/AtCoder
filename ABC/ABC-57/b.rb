N,M = gets.split.map(&:to_i)
Vector = Struct.new(:x,:y)
n = []
m = []
N.times do
	x,y = gets.split.map(&:to_i)
	n << Vector.new(x,y)
end

M.times do
	x,y = gets.split.map(&:to_i)
	m << Vector.new(x,y)
end

score = Array.new(N){Float::INFINITY}
point = Array.new(N)
N.times do |i|
	M.times do |j|
		tmp = (n[i].x - m[j].x).abs + (n[i].y - m[j].y).abs
		if tmp < score[i]
			score[i] = tmp
			point[i] = j
		end
	end
end

N.times do |i|
	puts point[i]+1
end






