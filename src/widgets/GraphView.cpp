#include "GraphView.h"
#include "matplot/freestanding/plot.h"
#include "matplot/matplot.h"
#include "notcurses/notcurses.h"
#include <ncpp/Plane.hh>
#include <ncpp/Visual.hh>
#include <string>

GraphView::GraphView(const std::string title, const GraphType graph_type,
                     GraphData &data, ncpp::Plane &plane, ncpp::Visual &visual)
    : m_title(title), m_graph_type(graph_type), m_plane(plane),
      m_visual(visual) {

  m_cols = data.size();
  this->m_data = data;
  if (graph_type == GraphType::bar_plot)
    auto graph = matplot::bar(data);
  else if (graph_type == GraphType::line_plot)
    auto graph = matplot::plot(data);
};

GraphData GraphView::GraphView::get_data() { return m_data; };
int GraphView::get_num_cols(int row) { return m_data[row].size(); };
int GraphView::get_num_rows() { return m_data.size(); };
std::array<uint, 2> GraphView::get_widget_size() { return m_widget_size; };
std::array<uint, 2> GraphView::get_graph_size() { return m_graph_size; };
