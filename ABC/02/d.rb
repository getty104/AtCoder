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

n,m=gi
d = darray n,n,false

rep n do |i|
  d[i][i] = true
end

rep m do
  a,b=gi
  d[a-1][b-1] = true
  d[b-1][a-1] = true
end

num = (0..n-1).to_a
mx = 0
repl 1,n do |i|
  td = num.combination(i)
  td.each do |t|
    flag = true
    t.each do |t1|
      t.each do |t2|
        flag &&= d[t1][t2]
      end
    end
    mx = i if flag
  end
end

puts mx
