#include <backend/linux/opengl/OpenGLHook.h>
#define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092
typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);

namespace spruce {
	extern GLXContext* context;

	OpenGLHook::OpenGLHook(Display* display) {
		this->display = display;
		static GLint vatt[] = {
			GLX_X_RENDERABLE, True,
			GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
			GLX_RENDER_TYPE, GLX_RGBA_BIT,
			GLX_RED_SIZE, 8,
			GLX_GREEN_SIZE, 8,
			GLX_BLUE_SIZE, 8,
			GLX_ALPHA_SIZE, 8,
			GLX_DEPTH_SIZE, 24,
			GLX_STENCIL_SIZE, 8,
			GLX_DOUBLEBUFFER, True,
			None
		};
		int32 fbcount;
		GLXFBConfig* fbc = glXChooseFBConfig(display, DefaultScreen(display), vatt, &fbcount);
		int best_fbc = -1, worst_fbc = -1, best_num_samp = -1, worst_num_samp = 999;
		for (int32 i = 0; i < fbcount; i++) {
			XVisualInfo *vi = glXGetVisualFromFBConfig(display, fbc[i]);
			if (vi){
				int samp_buf, samples;
				glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLE_BUFFERS, &samp_buf);
				glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLES, &samples);
				if (best_fbc < 0 || (samp_buf && samples > best_num_samp)) {
					best_fbc = i, best_num_samp = samples;
				}
				if (worst_fbc < 0 || !samp_buf || samples < worst_num_samp) {
					worst_fbc = i, worst_num_samp = samples;
				}
			}
			XFree(vi);
		}
		fbConfig = fbc[best_fbc];
		visualInfo = glXGetVisualFromFBConfig(display, fbConfig);
		XFree(fbc);
		context = 0;
		window = 0;
	}

	OpenGLHook::~OpenGLHook() {
		XFree(visualInfo);
	}

	Visual* OpenGLHook::getVisual() {
		return visualInfo->visual;
	}

	uint32 OpenGLHook::getDepth() {
		return visualInfo->depth;
	}

	void OpenGLHook::windowCreated(XWindow window) {
		glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
		glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddressARB( (const GLubyte*) "glXCreateContextAttribsARB" );
		GLint catt[] {
			GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
			GLX_CONTEXT_MINOR_VERSION_ARB, 2,
			//GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			None
		};
		context = glXCreateContextAttribsARB(display, fbConfig, 0, True, catt);
		spruce::context = &context;
		XSync(display, False);
		this->window = window;
		glXMakeCurrent(display, window, context);
		glewInit();
	}
}
