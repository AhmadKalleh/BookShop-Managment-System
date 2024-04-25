#pragma once
#include<iostream>
#include"clsUser.h"

namespace
{
	extern clsUser CurrentUser = clsUser::Find("", "");
}
