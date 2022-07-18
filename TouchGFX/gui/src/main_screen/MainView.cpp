#include <gui/main_screen/MainView.hpp>
#include "BitmapDatabase.hpp"
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainView::MainView()
{
}

void MainView::setupScreen()
{
}

void MainView::tearDownScreen()
{
}

void MainView::clickButtonPressed()
{
    int tmpVal = Unicode::atoi(countTxt.getWildcard());
    if (tmpVal <= 50)
    {
        tmpVal++;
//        countTxtBuffer[0]='1';
//        countTxtBuffer[1]='3';
//        countTxtBuffer[2]=0;
//
//
//
//        my_textBuffer[0]='a';
//        my_textBuffer[1]='b';
//        my_textBuffer[2]=0;


        Unicode::snprintf(countTxtBuffer, COUNTTXT_SIZE, "%d", tmpVal);
        //Unicode::snprintf(charTxtBuffer, CHARTXT_SIZE, "abcdefgh");
        Unicode::snprintf(charTxtBuffer, CHARTXT_SIZE, "abcAbc123");
        countTxt.invalidate();
        charTxt.invalidate();
//        if (repeatButton.getAlpha() == 100)
//        {
//            repeatButton.setAlpha(255);
//            repeatButton.setTouchable(true);
//            repeatButton.invalidate();
//        }
//        if (tmpVal == 50)
//        {
//            clickButton.setAlpha(100);
//            clickButton.setTouchable(false);
//            clickButton.setPressed(false);
//            clickButton.invalidate();
//
//            touchButton.setAlpha(100);
//            touchButton.setTouchable(false);
//            touchButton.setPressed(false);
//            touchButton.invalidate();
//        }
    }
}

void MainView::touchButtonPressed()
{
    int tmpVal = Unicode::atoi(countTxt.getWildcard());
    if (tmpVal <= 50)
    {
        tmpVal++;
        Unicode::snprintf(countTxtBuffer, COUNTTXT_SIZE, "%d", tmpVal);
        countTxt.invalidate();
        if (repeatButton.getAlpha() == 100)
        {
            repeatButton.setAlpha(255);
            repeatButton.setTouchable(true);
            repeatButton.invalidate();
        }

        if (tmpVal == 50)
        {
            clickButton.setAlpha(100);
            clickButton.setTouchable(false);
            clickButton.setPressed(false);
            clickButton.invalidate();

            touchButton.setAlpha(100);
            touchButton.setTouchable(false);
            touchButton.setPressed(false);
            touchButton.invalidate();
        }
    }
}

void MainView::repeatButtonPressed()
{
    int tmpVal = Unicode::atoi(countTxt.getWildcard());
    if (tmpVal >= 0)
    {
        tmpVal--;
        Unicode::snprintf(countTxtBuffer, COUNTTXT_SIZE, "%d", tmpVal);
        countTxt.invalidate();
        if (clickButton.getAlpha() == 100)
        {
            clickButton.setAlpha(255);
            clickButton.setTouchable(true);
            clickButton.invalidate();

            touchButton.setAlpha(255);
            touchButton.setTouchable(true);
            touchButton.invalidate();
        }

        if (tmpVal <= 0)
        {
            repeatButton.setAlpha(100);
            repeatButton.setTouchable(false);
            repeatButton.setPressed(false);
            repeatButton.invalidate();
        }
    }
}

void MainView::toggleButtonPressed()
{
    if (countTxt.getColor() == Color::getColorFromRGB(222, 222, 222))
    {
        countTxt.setColor(Color::getColorFromRGB(231, 154, 9));
        toggleButton.setText(TypedText(T_TOGGLEBUTTONORANGE));
    }
    else
    {
        countTxt.setColor(Color::getColorFromRGB(222, 222, 222));
        toggleButton.setText(TypedText(T_TOGGLEBUTTONWHITE));
    }
    countTxt.invalidate();
    toggleButton.invalidate();
}
