#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <ncpp/Visual.hh>
#include <array>
#include <string>
#include <vector>

enum GraphType { bar, line };
enum ImageType { svg, png, jpg };
constexpr std::string_view to_string(GraphType g);

using GraphData = std::vector<std::vector<int>>;

class GraphView {
public:
  GraphData get_data();
  int get_num_cols();
  int get_num_rows(int col);
  std::array<uint, 2> get_widget_size();
  std::array<uint, 2> get_graph_size();
  void save_graph_as(ImageType image_type, std::string fp);

  GraphView(std::string title, const GraphType graph_type, GraphData data);
  ~GraphView() = default;

private:
  ncpp::Plane nc_plane();
  ncpp::Visual nc_visual();
  const std::string title;
  const GraphType graph_type;
  std::string graph_fp;
  int n_cols;
  int n_rows;
  GraphData data;
  std::array<uint, 2> graph_size;
  std::array<uint, 2> widget_size;
};
