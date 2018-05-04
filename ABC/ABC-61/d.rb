require 'prime'
require 'set'
require 'tsort'
include Math
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
def digit(num);            num.to_s.length                            end
def array(s,ini=nil);      Array.new(s){ini}                          end
def darray(s1,s2,ini=nil); Array.new(s1){Array.new(s2){ini}}          end
def rep(num);              num.times{|i|yield(i)}                     end
def repl(st,en,n=1);       st.step(en,n){|i|yield(i)}                 end

require('forwardable')

class Node
  attr_reader :name

  def initialize(name)
    self.name = name
  end

  def ==(other)
    name == other.name
  end

  private

  attr_writer :name
end

class Edge
  attr_reader :from, :to, :weight

  def initialize(from, to, weight = nil)
    self.from = from
    self.to = to
    self.weight = weight
  end

  private

  attr_writer :from, :to, :weight
end

class Graph
  attr_reader :edges

  def initialize(edges)
    self.edges = edges
  end

  def nodes
    @nodes ||= edges.flat_map { |edge| [edge.from, edge.to] }.uniq
  end

  def neighbor_edges_of(node)
    edges.select { |edge| edge.from == node }
  end

  def start_node
    @start_node ||= (nodes - edges.map(&:to)).first
  end

  def finish_node
    @finish_node ||= (nodes - edges.map(&:from)).first
  end

  private

  attr_writer :edges
end

class DijkstrasAlgorithm
  class Node < Node
    attr_accessor :cost, :parent

    def initialize(name: nil, cost: nil, parent: nil)
      super(name)
      self.cost = cost
      self.parent = parent
      self.processed = false
    end

    def processed!
      self.processed = true
    end

    def processed?
      processed
    end

    private

    attr_accessor :processed
  end

  extend Forwardable

  private_class_method :new

  def self.call(graph)
    new(graph).send(:call)
  end

  private

  attr_accessor :graph
  def_delegators :graph, :nodes, :edges, :neighbor_edges_of, :start_node, :finish_node

  def initialize(original_graph)
    initialize_graph_by(original_graph)
    initialize_node_properties
  end

  def call
    update_node_costs!
    build_shortest_route
  end

  def initialize_graph_by(original_graph)
    new_nodes = initialize_nodes_by(original_graph.nodes)
    new_edges = initialize_edges_by(original_graph.edges, new_nodes)

    self.graph = Graph.new(new_edges)
  end

  def initialize_nodes_by(original_nodes)
    original_nodes.map { |original_node| Node.new(name: original_node.name) }
  end

  def initialize_edges_by(original_edges, new_nodes)
    original_edges.map do |original_edge|
      Edge.new(
               new_nodes.find { |new_node| new_node == original_edge.from },
               new_nodes.find { |new_node| new_node == original_edge.to },
               original_edge.weight
               )
    end
  end

  def initialize_node_properties
    start_edges = edges.select { |edge| edge.from == start_node }
    nodes.each do |node|
      next node if start_node == node

      start_edge = start_edges.find { |edge| edge.to == node }

      if start_edge
        node.cost = start_edge.weight
        node.parent = start_node
      else
        node.cost = 0
        node.parent = nil
      end
    end
  end

  def update_node_costs!
    loop do
      node = find_lowest_cost_node
      break unless node

      neighbor_edges_of(node).each do |edge|
        new_cost = node.cost + edge.weight

        if edge.to.cost < new_cost
          edge.to.cost = new_cost
          edge.to.parent = node
        end
      end

      node.processed!
    end

    true
  end

  def build_shortest_route
    ordered_nodes = [finish_node]
    loop do
      node = nodes.find { |node| node == ordered_nodes.first.parent }
      ordered_nodes.unshift(node)
      break unless node.parent
    end
    ans = 0
    ordered_nodes.map { |node| ans += node.cost if node.cost != nil }
    ans
  end

  def find_lowest_cost_node
    nodes
    .reject { |node| node.cost.nil? || node.processed? }
    .min_by(&:cost)
  end
end


n,m = gi
l  =  Hash.new

node = []
rep n do |i|
  node <<Node.new((i+1).to_s)
end
list = []
rep m do
  a,b,c = gi
  list <<Edge.new(node[a-1],node[b-1],c)
end
g = Graph.new list

p DijkstrasAlgorithm.call(g)