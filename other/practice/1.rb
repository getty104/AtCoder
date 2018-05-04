meth = <<~EOS
def culc a,b,c,s 
	num = a+b+c
	return num.to_s+ " " +s
end
EOS
R = RubyVM::InstructionSequence
R.compile_option = {tailcall_optimization: true, trace_instruction: false}
R.new(meth).eval

a = gets.to_i
b,c = gets.split.map(&:to_i)
s = gets.chomp

puts culc(a,b,c,s)
