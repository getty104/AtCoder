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

s = gsf
x,y = gi
d = s.split('T').map{|ss|ss.size}
dpx = darray d.size, 20000, false
dpy = darray d.size, 20000, false
dpx[0][d[0]] = true
dpy[0][d[1]] = true
idx = 0
idy = 1
repl 2, d.size - 1, 2 do |i|
  idx+=2
  rep x+1 do |tx|
    dpx[i][tx] = dpx[i - 2][tx - d[i]] || dpx[i - 2][tx + d[i]]
  end
end

repl 3, d.size - 1, 2 do |i|
  idy += 2
  rep y+1 do |ty|
    dpy[i][ty] = dpy[i - 2][ty - d[i]] || dpy[i - 2][ty + d[i]]
  end
end


puts dpx[idx][x] && dpy[idy][y] ? 'Yes' : 'No'
