/*******************************************************************************
 *
 *  VTMine Framework.
 *  (c) xidv.ru 2014–2020.
 *
 *  This source is for internal use only — Restricted Distribution.
 *  All rights reserved.
 *
 ******************************************************************************/

#include "framework_def_impl.h"

namespace vtmine {

FrameworkDefImpl::~FrameworkDefImpl()
{
    delete _settings;
}


void FrameworkDefImpl::init(CmdLineParams& params)
{
    _settings = new FrameworkSettings(params.getPlugins());
}


} // namespace vtmine
