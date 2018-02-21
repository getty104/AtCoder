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

N = gif
t = gi
v = gi
repl 1, N-1 do |i|
  t[i] += t[i-1]
end

t.map!{|i| i * 2 }
t << 0

x = [0] * (t[-2] + 1)

rep N do |i|
  if v[i] < x[t[i - 1]]
    x[t[i - 1]] = v[i]
    repl t[i - 1] - 1, t[i - 2], -1 do |j|
      x[j] = [x[j + 1] + 0.5, x[j]].min
    end
  end

  repl t[i - 1] + 1, t[i] do |j|
    x[j]=[x[j-1]+0.5, v[i]].min
  end
end

x[-1]=0
repl t[-2], 1, -1 do |i|
  x[i-1] = [x[i-1], x[i]+0.5].min
end

puts x.each_cons(2).map{|l, r|
  (l + r)*0.5/2.0
}.inject(:+)
