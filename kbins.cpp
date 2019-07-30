#define WEBVIEW_IMPLEMENTATION
#include "webview.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

typedef struct webview Webview;

/** 
 * LOGIC OVERVIEW
 * 
 * Read the .json for a list of todos and a list of dones. Pass that to the
 * javascript page. The javascript page should populate the todos and dones
 * in the webpage. 
 * 
 * On a drop event, the item should be removed from the origin list and added to
 * the destination list in the corresponding place.
 * 
 */

void create_webview(Webview& w) {
  memset(&w, 0, sizeof(Webview));
  w.title = "KBins: Todo Bins";
  w.url = "file:///home/kasra/projects/kbins/kbins.html";
  w.width = 800;
  w.height = 600;
  w.resizable = true;
  w.external_invoke_cb = [](Webview* w, const char* data) {
    if (data == std::string("load")) {
      std::cout << "loading..." << std::endl;

      std::stringstream buffer;
      std::ifstream in {"todo.json"};
      buffer << in.rdbuf();
      const std::string jseval = "state = `" + buffer.str() + "`; render(JSON.parse(state));";
      webview_eval(w, jseval.c_str());
    } else {
      std::cout << "saving..." << std::endl;
      std::ofstream out {"todo.json"};
      out << data;
    } 
  };
  w.debug = true;

  int r = webview_init(&w);
  if (r != 0) exit(r);
}

int main() {
  Webview w;
  create_webview(w);
  while (webview_loop(&w, 1) == 0) ;
  webview_exit(&w);
  return 0;
}
