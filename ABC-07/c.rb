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
r,c = gi
sy,sx = gi
sy-=1
sx-=1
gy,gx = gi
gy-=1
gx-=1
mp = []
rep r do
  mp << gc
end
set = Set.new
states = []
states << [sy,sx,0,-1,-1]
ans = INF
dy = [0,1,0,-1]
dx = [1,0,-1,0]
while states.size > 0
  state = states.shift
  jd = [state[0],state[1]]
  next if set.include? jd
  set << jd
  if state[0] == gy && state[1] == gx
    ans = state[2]
    break
  end

  rep 4 do |i|
    ty = state[0] + dy[i]
    tx = state[1] + dx[i]
    states << [ty,tx,state[2]+1,state[0],state[1]] if ty >= 0 && ty < r && tx >= 0 && tx < c && mp[ty][tx] == '.' && (ty != state[3] || tx != state[4])
  end
end
puts ans
