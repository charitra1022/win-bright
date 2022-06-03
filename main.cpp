#include <iostream>
#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/checkbutton.h>

class HelloWorld : public Gtk::Window
{
    protected:
      //Signal handlers:
      void on_slider_changed();
      void on_checkbtn_checked();
      void changeBrighness(int);

      //Member widgets:
      Gtk::Scale slider_wid;    //slider
      Gtk::Box hbox1, hbox2;    //horizontal layouts
      Gtk::Box vbox;            //main vertical layout
      Gtk::Label disp;          //slider value display label
      Gtk::Label info1, info2;  //information labels
      Gtk::CheckButton checkBtn;    //advanced setting checkbox


    public:
        HelloWorld(){
            set_title("Brightness Adjustment");

            hbox1 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
            hbox2 = Gtk::Box(Gtk::Orientation::HORIZONTAL);
            vbox = Gtk::Box(Gtk::Orientation::VERTICAL);

            hbox1.set_margin(20);
            hbox2.set_margin(20);
            hbox2.set_spacing(20);
            vbox.set_margin(20);

            set_child(vbox);    //set this layout as main layout of application

            info1 = Gtk::Label("Slide the slider to change the brightness.");
            info1.set_overflow(Gtk::Overflow::VISIBLE);
            vbox.append(info1);     //add info label to main layout

            //slider widget
            slider_wid = Gtk::Scale();
            slider_wid.set_range(10, 100);
            slider_wid.signal_value_changed().connect(sigc::mem_fun(*this, &HelloWorld::on_slider_changed));
            slider_wid.set_value(30);

            hbox1.append(slider_wid);   //add slider to horizontal layout
            slider_wid.set_expand();

            //slider value display label widget
            disp = Gtk::Label(Glib::ustring::format(slider_wid.get_value()));
            hbox1.append(disp);         //add slider label to horizontal layout
            vbox.append(hbox1);         //add horizontal layout to main layout


            //checkbox button widget
            checkBtn = Gtk::CheckButton();
            checkBtn.signal_toggled().connect(sigc::mem_fun(*this, &HelloWorld::on_checkbtn_checked));
            hbox2.append(checkBtn);     //add checkbox to horizontal layout


            info2 = Gtk::Label("Advanced brightness control. For increasing brightness over the maximum!");
            info2.set_expand();
            info2.set_overflow(Gtk::Overflow::VISIBLE);

            hbox2.append(info2);         //add checkbox info to horizontal layout
            vbox.append(hbox2);          //add horizontal layout to main layout

      }
      ~HelloWorld() {};
};

void HelloWorld::on_slider_changed(){
    int val = (int)this->slider_wid.get_value();
    this->disp.set_text(Glib::ustring::format(val));
    this->changeBrighness(val);
}
void HelloWorld::on_checkbtn_checked(){
    bool state = this->checkBtn.get_active();
    if (state) {
        std::cout << "Checked - Yes" << std::endl;
        this->slider_wid.set_range(10, 150);
    } else {
         std::cout << "Checked - No" << std::endl;
         this->slider_wid.set_range(10, 100);
    }
}

void HelloWorld::changeBrighness(int value) {
    std::cout << "Brightness - " << value << std::endl;
}

int main(int argc, char* argv[]){
  auto app = Gtk::Application::create("com.charitraagarwal.brightnessadjustment");
  return app->make_window_and_run<HelloWorld>(argc, argv);
}
