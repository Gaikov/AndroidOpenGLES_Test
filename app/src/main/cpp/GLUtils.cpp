//
// Created by Roman Gaikov on 2019-07-18.
//

#include "GLUtils.h"
#include "headers.h"

struct glError_t
{
	GLenum code;
	const char *message;
};

static glError_t errors[] = {
		{
				GL_INVALID_ENUM,
				"An unacceptable value is specified for an enumerated argument."
		},

		{
				GL_INVALID_VALUE,
				"A numeric argument is out of range."
		},

		{
				GL_INVALID_OPERATION,
				"The specified operation is not allowed in the current state."
		},
/*
		{
				GL_INVALID_FRAMEBUFFER_OPERATION,
				"The command is trying to render to or read from the framebuffer while the currently bound framebuffer is not framebuffer complete (i.e. the return value from glCheckFramebufferStatus is not GL_FRAMEBUFFER_COMPLETE)."
		},
*/
        {
                GL_STACK_OVERFLOW,
                "GL_STACK_OVERFLOW"
        },
        {
                GL_STACK_UNDERFLOW,
                "GL_STACK_UNDERFLOW"
        },
		{
				GL_OUT_OF_MEMORY,
				"There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded."
		}
};

bool GLUtils::hasError(const char* funcName)
{
	auto code = glGetError();
	if (!code)
	{
		return false;
	}

	for (auto error : errors)
	{
		if (error.code == code)
		{
			printf("GL ERROR: %s: %s\n", funcName, error.message);
			return true;
		}
	}

	printf("GL ERROR: unknown error\n");
	return true;
}
