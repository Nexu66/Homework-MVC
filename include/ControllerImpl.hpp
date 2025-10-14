#include"interfaces/View.hpp"
#include"interfaces/Module.hpp"
namespace controller::impl
{
   class ControllerImpl{
    public:
  view::View* m_ui;
  module::Module* m_processor;
  void PromptUser() const;

  void UpdateUI() const;

  ControllerImpl(view::View* ui, module::Module* processor);
   }; 
} // namespace impl

