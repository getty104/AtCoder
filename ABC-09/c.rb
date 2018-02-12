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
n, k = gi
s = gc
sorted = s.sort

def diff(arr1, arr2)
  a = arr1.dup
  arr2.each do |i|
    j = a.index(i)
    a.delete_at(j) if j
  end
  return a
end

t = ""
rep n do |i|
  a = s[0..i]
  b = s[(i+1)..-1]
  sorted.each.with_index do |v, idx|
    ad = a.zip((t+v).chars).select {|ii,j| ii != j }.count
    copied = sorted.dup
    copied.delete_at(idx)
    bd = diff(b, copied).size
    if ad + bd <= k
      t += v
      sorted.delete_at(idx)
      break
    end
  end
end
puts t
