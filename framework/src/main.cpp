/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework main module
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      09.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Main startup module.
 *
 ******************************************************************************/

#include <QApplication>
#include <QPushButton>
#include <QWidget>

#include "core/app_starter.h"


int main(int argc, char* argv[])
{
    using namespace vtmine;

    AppStarter appStarter;
    return appStarter.run(argc, argv);
}

