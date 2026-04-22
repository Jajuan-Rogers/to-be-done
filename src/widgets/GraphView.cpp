#include "GraphView.h"
#include "matplot/matplot.h"
#include "notcurses/notcurses.h"
#include <string>

GraphView::GraphView(const std::string title, const GraphType graph_type,
                     GraphData data)
    : title(title), graph_type(graph_type) {
  this->data = data;
};

GraphData GraphView::GraphView::get_data() { return data; };

int GraphView::get_num_cols() { return data.size(); };
int GraphView::get_num_rows(int col) { return data[col].size(); };

std::array<uint, 2> GraphView::get_widget_size() { return widget_size; };

std::array<uint, 2> GraphView::get_graph_size() { return graph_size; };
