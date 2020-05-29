#include "lamaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
lamaApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

lamaApp::lamaApp(InputParameters parameters) : MooseApp(parameters)
{
  lamaApp::registerAll(_factory, _action_factory, _syntax);
}

lamaApp::~lamaApp() {}

void
lamaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"lamaApp"});
  Registry::registerActionsTo(af, {"lamaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
lamaApp::registerApps()
{
  registerApp(lamaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
lamaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lamaApp::registerAll(f, af, s);
}
extern "C" void
lamaApp__registerApps()
{
  lamaApp::registerApps();
}
