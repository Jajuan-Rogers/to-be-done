#pragma once
#include <array>
#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <ncpp/Visual.hh>
#include <string>
#include <vector>

enum GraphType { bar_plot, line_plot };
enum ImageType { svg, png, jpg };
constexpr std::string_view to_string(GraphType g);

using GraphData = std::vector<std::vector<double>>;

class GraphView {
public:
  GraphData get_data();
  int get_num_cols(int row);
  int get_num_rows();
  std::array<uint, 2> get_widget_size();
  std::array<uint, 2> get_graph_size();
  void save_graph_as(ImageType image_type, std::string fp);
  void display_data();
  void update_displated_data(GraphData& data);
  void colorize_data(std::array<unsigned int,3> colors); // 3 colors that will determine the colors of high medium and low values 

  GraphView(std::string title, const GraphType graph_type,
            GraphData &data, ncpp::Plane &nc_plane,
            ncpp::Visual &nc_visual);
  ~GraphView() = default;

private:

  ncpp::Plane m_plane;
  ncpp::Visual m_visual;
  const std::string m_title;
  const GraphType m_graph_type;
  std::string m_graph_fp;
  std::array<unsigned int, 4> data_colors;
  int m_cols;
  int m_rows;
  GraphData m_data;
  std::array<uint, 2> m_graph_size;
  std::array<uint, 2> m_widget_size;
};
