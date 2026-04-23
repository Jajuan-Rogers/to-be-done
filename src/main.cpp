#include "3rd_party/matplot/source/matplot/core/figure_registry.h"
#include "3rd_party/matplot/source/matplot/freestanding/plot.h"
#include "widgets/GraphView.h"
#include <cstdint>
#include <iostream>
#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <ncpp/Visual.hh>
#include <matplot/matplot.h>
#include <notcurses/notcurses.h>




void display_image(ncpp::Plane& tp){
  ncpp::Visual n_vis("/home/benten/projects/programming/cpp/to-be-done/src/assets/images/double_devil.jpg");
  struct ncvisual_options vopts = {};
  vopts.n = tp;
  vopts.scaling = NCSCALE_SCALE;
  n_vis.blit(&vopts);
}




int main() {
  try {
    ncpp::NotCurses nc;
    ncpp::Plane *nc_plane_1 = nc.get_stdplane();
    ncpp::Plane *nc_plane_2 = nc.get_stdplane();
    ncpp::Plane *nc_plane_3 = nc.get_stdplane();

    


    nc_plane_1->set_fg_rgb(0x0A5FF2);
    nc_plane_2->set_fg_rgb(0xF20AA9);
    nc_plane_2->set_bg_rgb(0xF20AA9);

    display_image(*nc_plane_1);


    int x_1;
    int x_2;

    int y_1;
    int y_2;

    nc_plane_1->putstr(x_1, y_1, "Hello from not curses");
    nc_plane_2->putstr(x_1, y_1, "my name is jajuan");

    nc.render();

    ncinput ni;
    while (true) {
      uint32_t key = nc.get(nullptr, &ni);

      if (key == 'q' || key == 'Q') {
        break;
      }

      if (key == 'k' || key == 'K') {
        nc_plane_1->printf(10, 10, "You pressed key code %d ", key);
        nc.render();
      }
    };
  } catch (const std::exception &e) {
    // C++ wrapper throws standard exceptions on failure
    std::cerr << "Notcurses Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
