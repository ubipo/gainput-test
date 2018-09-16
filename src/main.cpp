#include <thread>
#include <iostream>
#include <chrono>
#include <thread>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <gainput/gainput.h>

using namespace std;

int main(int argc, char *argv[]) {
  enum Button {
    ButtonConfirm
  };

  gainput::InputManager manager;
  gainput::InputMap inputMap(manager);

  manager.SetDisplaySize(100, 100);
  const gainput::DeviceId padId = manager.CreateDevice<gainput::InputDevicePad>();
  gainput::InputDevice* device = manager.GetDevice(padId);

  cout << "Available: " << device->IsAvailable() << endl;
  cout << "State: " << device->GetState() << endl;

  inputMap.MapBool(ButtonConfirm, padId, gainput::PadButtonA);


  while (true) {
    manager.Update();

    if (inputMap.GetBoolIsNew(ButtonConfirm)) {
      cout << "Confirm pressed!" << endl;
    }
  }

  return 0;
}
