#include <windows.h>
int percent_to_gamma(int);
int gamma_to_percent(int);
void applyBrighness(int);
int getBrightness(void);
void displayDeviceGamma(void);
WINBOOL changeGamma(int);


class ScopedDC {
    //Contains methods for creation, deletion and getting Device Contexts for entire screen.

    private:
        HDC _screenHdc;

    public:
        HDC getHdc() {
            //returns the device context
            return this->_screenHdc;
        }

        ScopedDC(){
            //constructor that creates the device context.
            this->_screenHdc = GetDC(0);
            if(_screenHdc)
                std::cout<<"HDC Created." << std::endl;
        };

        ~ScopedDC() {
            //destructor that releases the device context on object destruction
            int status = ReleaseDC(NULL, this->_screenHdc);
            if(status)
                std::cout<<"HDC Released." << std::endl;
        }
};


int percent_to_gamma(int percent) {
    //converts percent to a value between 0-128
    if (percent>150) percent=150;
    if (percent<10) percent=10;
    int value = (percent*128)/100;
    return value;
}

int gamma_to_percent(int gammaVal){
    //converts a value between 0-128 into percent
    int percent = std::round((gammaVal*100)/128);
    return percent;
}

void applyBrighness(int percent) {
    //This is called from UI itself. Accepts percent and calls API functions.

    int gammaVal = percent_to_gamma(percent);

    std::cout << "Brightness - " << percent << std::endl;
    std::cout << "Gamma - " << gammaVal << std::endl;

    if (changeGamma(gammaVal))
        std::cout << "Brightness Set!" << std::endl;
    std::cout << "------------------------------\n\n";
}

int getBrightness() {
    //gets the current brightness value from the device gamma.

    ScopedDC hdc;

    WORD GammaArray[3][256];    //for storing gamma values
    WINBOOL status = GetDeviceGammaRamp(hdc.getHdc(), GammaArray);

    int secondVal = GammaArray[0][1]; //256 original
    int percent = gamma_to_percent(secondVal-128);

    std::cout << "------------\n\n";
    std::cout << "GammaArray[0][1] is " << secondVal << std::endl;
    std::cout << "Brightness Value is " << percent << std::endl;
    std::cout << "------------\n\n";

    return percent;
}

void displayDeviceGamma() {
    //displays the device gamma values

    ScopedDC hdc;
    WORD GammaArray[3][256];    //for storing gamma values
    WINBOOL status = GetDeviceGammaRamp(hdc.getHdc(), GammaArray);

    if (status) {
        std::cout << "\n\nRed Values" << std::endl << std::endl;
        for(int i=0; i<256; i++) {
            std::cout << GammaArray[0][i] << " ";
        }
        std::cout << "\n\nGreen Values" << std::endl << std::endl;
        for(int i=0; i<256; i++) {
            std::cout << GammaArray[1][i] << " ";
        }
        std::cout << "\n\nBlue Values" << std::endl << std::endl;
        for(int i=0; i<256; i++) {
            std::cout << GammaArray[2][i] << " ";
        }
    }
}

WINBOOL changeGamma(int gammaVal) {
    //accepts a value between 0-128 and sets the GammaArray accordingly

    WORD GammaArray[3][256];    //for storing gamma values

    for(int i=0; i<256; i++) {
        int iValue = i*(gammaVal + 128);
        if(iValue > 65535)  iValue = 65535;
        GammaArray[0][i] = GammaArray[1][i] = GammaArray[2][i] = (WORD)iValue;
    }
    ScopedDC hdc;
    WINBOOL status = SetDeviceGammaRamp(hdc.getHdc(), GammaArray);
    return status;
}

