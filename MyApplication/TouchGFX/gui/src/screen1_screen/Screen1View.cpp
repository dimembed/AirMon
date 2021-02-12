#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::setDataScdUi(SCD30MSG scd_msr)
{
	int leftp;
	int rightp;

 	leftp = (int)(scd_msr.Co2_msg);
	//rightp = ((int)((uirscdmsr->temp)*100))%100;
 	rightp = 0;

    //update text area
    Unicode::itoa(leftp, textArea1Buffer, TEXTAREA1_SIZE, 10);
    textArea1.invalidate();

}
