require 'prime'
require 'set'
require 'tsort'
include Math
ALP = ('a'..'z').to_a
INF = 0xffffffffffffffff
def max(a,b);              a > b ? a : b                              end
def min(a,b);              a < b ?  a : b                             end
def swap(a,b);             a, b = b, a                                end
def gif;                   gets.to_i                                  end
def gff;                   gets.to_f                                  end
def gsf;                   gets.chomp                                 end
def gi;                    gets.split.map(&:to_i)                     end
def gf;                    gets.split.map(&:to_f)                     end
def gs;                    gets.chomp.split.map(&:to_s)               end
def gc;                    gets.chomp.split('')                       end
def pr(num);               num.prime_division                         end
def pr?(num);              Prime.prime?(num)                          end
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end

n = gif
a = gi
b = []
if n % 2 == 0
  repl n-1, 1, -2 do |variable|
    b << variable
  end

  repl 1, n-1,2 do |variable|
    b << variable
  end
else
  repl n-1, 0, -2 do |variable|
    b << variable
  end

  repl 2, n-1, 2 do |variable|
    b << variable
  end
end


aa = Hash.new
bb = Hash.new
a.each do |ta|
  aa[ta] ||= 0
  aa[ta] += 1
end

b.each do |tb|
  bb[tb] ||= 0
  bb[tb] += 1
end

jd = true
b.each do |i|
  if bb[i] != aa[i]
    jd = false
    break
  end
end

ans = jd ? 2 ** (n/2) : 0
puts ans % (10**9 + 7)
