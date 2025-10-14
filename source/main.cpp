#include <iostream>

#include "Controller.hpp"

int main() {
  controller::Controller c{new view::CLIUserInterface{},
                           new module::SummarizeSuquence{}};

  c.PromptUser();
  c.UpdateUI();
}