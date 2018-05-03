#ifndef _CONFIG_H
#define _CONFIG_H
#pragma once

//#include "dependencies.h"

#include "common.h"
#include "helper.h"
#include "registry.h"

#include "../versioning/version.h"

namespace Configuration
{
	#define CONFIG_DEFAULT_LOGIN_TEXT ENDPOINT_NAME" Login"

	#define CONFIG_DEFAULT_TIMEOUT_IN_SECS 60
	
	#define CONFIG_SSL_IGNORE_UNKNOWN_CA_TRUE 1
	#define CONFIG_SSL_IGNORE_UNKNOWN_CA_FALSE 0

	#define CONFIG_SSL_IGNORE_INVALID_CN_TRUE 1
	#define CONFIG_SSL_IGNORE_INVALID_CN_FALSE 0

	/////////////////// BASE

	struct CONFIGURATION
	{
		char server_url[1024];
		char login_text[64];

		/*int ssl_verify_hostname;
		int ssl_verify_signature;*/

		char v1_bitmap_path[1024];
		char v2_bitmap_path[1024];

		int two_step_hide_otp;
		int two_step_send_password;

		int ssl_ignore_unknown_ca;
		int ssl_ignore_invalid_cn;
	};

	CONFIGURATION*& Get();
	void Default();
	void Init();
	void Deinit();

	////////////////// SPECIFIC

	void Read();
	DWORD SaveValueString(CONF_VALUE conf_value, char* value, int size);
	DWORD SaveValueInteger(CONF_VALUE conf_value, int value);
}

#endif