#include <algorithm>
#include <cmath>
#include <math.h>
#include <matplot/matplot.h>
#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <ncpp/Visual.hh>
#include <notcurses/notcurses.h>
#include <stdint.h>
#include <thread>

/**
 * @brief Generates a sine wave graph and saves it as a GIF.
 * * @param filename The output file name (must end in .gif)
 */
void generate_gif_graph(const std::string &filename) {
  using namespace matplot;

  // 1. Generate sample data (a smooth sine wave)
  std::vector<double> x = linspace(0, 2 * pi, 100);
  std::vector<double> y = transform(x, [](double val) { return std::sin(val); });

  // 2. Create the figure in "quiet mode" (true) to prevent UI pop-ups
  auto fig = figure(true);

  // 3. Plot the data and customize the visual appearance
  auto p = plot(x, y);
  p->line_width(2.5);
  p->color("blue");

  // Add labels and title
  title("Sine Wave Plot");
  xlabel("X-Axis (Radians)");
  ylabel("Amplitude");

  // 4. Save the figure
  // The library sees the ".gif" extension and automatically uses the GIF
  // terminal
  save(filename);
}

uint32_t get_fire_to_indigo(double t) {
  // Clamp t between 0 and 1 to prevent weird colors
  t = std::max(0.0, std::min(1.0, t));

  // Start (Fire Red)
  int sR = 255, sG = 36, sB = 0;
  // End (Indigo)
  int eR = 75, eG = 0, eB = 130;

  // Interpolate each channel
  int r = sR + static_cast<int>(t * (eR - sR));
  int g = sG + static_cast<int>(t * (eG - sG));
  int b = sB + static_cast<int>(t * (eB - sB));

  // Recombine into a single hex value (0xRRGGBB)
  return (static_cast<uint32_t>(r) << 16) | (static_cast<uint32_t>(g) << 8) |
         static_cast<uint32_t>(b);
}

int main() {
  generate_gif_graph("test_gif.png");
  ncpp::NotCurses nc;
  ncpp::Plane *stdp = nc.get_stdplane();
  ncpp::Visual ncv("assets/reaper.jpg");

  struct ncvisual_options vopts = {.n = nullptr,
                                   .scaling = NCSCALE_SCALE,
                                   .y = 2,
                                   .x = 5,
                                   .blitter = NCBLIT_BRAILLE};

  // ncpp::Plane* img_plane = ncpp::Plane::from_ncplane(ncv.blit(&vopts));
  nc.render();

  ncinput ni;

  int color_index = 0;

  double time = 0;

  while (true) {
    double t = 0.5 + 0.5 * std::sin(time);
    uint32_t curr_color = get_fire_to_indigo(t);
    stdp->set_fg_rgb(curr_color);
    stdp->putstr(10, 10, "Welcome to to-be-done");
    nc.render();

    time += 0.05;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  return 0;
}
