#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  // You will need to make changes to this code.

  try {
    // create a window and pass the reference to grid.init
    Xwindow wd = Xwindow(500, 500);
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;

        // create a grid, initialize it, and also pass the reference of the window to grid.init
        g.init(n, wd);
      }

      else if (cmd == "init") {
        int first = 0;
        int second = 0;
        cin >> first >> second;
        while ((first != -1) && (second != -1)) {
          g.turnOn(first, second);
          cin >> first >> second;
        }
        cout << g;
      }

      else if (cmd == "game") {
        cin >> moves;
        cout << moves << " moves left" << endl;
        if (moves == 0) {
          cout << "Won" << endl;
          break;
        }
      }

      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r, c);
        cout << g;
        -- moves;
        if (moves == 1) {
          cout << moves << " move left" << endl;
        }
        else {
          cout << moves << " moves left" << endl;
        }

        if (moves == 0) {
          if (g.isWon()) {
            cout << "Won" << endl;
          }
          else {
            cout << "Lost" << endl;
          }
          break;
        }
      }
    }
  }
  catch (ios::failure &) {
  }
}
