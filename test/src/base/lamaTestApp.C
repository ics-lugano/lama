//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "lamaTestApp.h"
#include "lamaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
lamaTestApp::validParams()
{
  InputParameters params = lamaApp::validParams();
  return params;
}

lamaTestApp::lamaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  lamaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

lamaTestApp::~lamaTestApp() {}

void
lamaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  lamaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"lamaTestApp"});
    Registry::registerActionsTo(af, {"lamaTestApp"});
  }
}

void
lamaTestApp::registerApps()
{
  registerApp(lamaApp);
  registerApp(lamaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
lamaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lamaTestApp::registerAll(f, af, s);
}
extern "C" void
lamaTestApp__registerApps()
{
  lamaTestApp::registerApps();
}
