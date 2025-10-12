#include <iostream>

#include "Controller.hpp"

int main() {
  controller::Controller c{new view::View{}, new module::Module{}};

  c.UpdateUI(c.ProcessSequence(c.PromptUser()));
}
