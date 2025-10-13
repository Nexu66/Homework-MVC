#include <iostream>

#include "Controller.hpp"

int main() {
  controller::Controller c{new view::View{}, new module::Module{}};

  c.PromptUser();
  c.UpdateUI();
}