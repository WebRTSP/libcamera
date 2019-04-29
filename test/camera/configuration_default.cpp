/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2019, Google Inc.
 *
 * libcamera Camera API tests
 */

#include <iostream>

#include "camera_test.h"

using namespace std;

namespace {

class ConfigurationDefault : public CameraTest
{
protected:
	int run()
	{
		std::unique_ptr<CameraConfiguration> config;

		/* Test asking for configuration for a video stream. */
		config = camera_->generateConfiguration({ StreamRole::VideoRecording });
		if (!config || !config->isValid()) {
			cout << "Default configuration invalid" << endl;
			return TestFail;
		}

		/*
		 * Test that asking for configuration for an empty array of
		 * stream roles returns an empty camera configuration.
		 */
		config = camera_->generateConfiguration({});
		if (!config || config->isValid()) {
			cout << "Failed to retrieve configuration for empty roles list"
			     << endl;
			return TestFail;
		}

		return TestPass;
	}
};

} /* namespace */

TEST_REGISTER(ConfigurationDefault);
