#include <backend/mac/CocoaWindow.h>
#include <backend/mac/SpruceView.h>
#include <backend/mac/opengl/OpenGLView.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/mac/metal/MetalView.h>
#include <log.h>

@implementation CocoaWindowObj
- (BOOL) canBecomeKeyWindow {
	return YES;
}

- (BOOL) canBecomeMainWindow {
	return YES;
}
@end

@implementation WindowDelegate
- (instancetype) initWithWindow:(spruce::Window*)_spruceWindow cocoaWindow:(NSWindow*)_cocoaWindow {
	spruceWindow = _spruceWindow;
	cocoaWindow = (CocoaWindowObj*) _cocoaWindow;
	return self;
}

- (void) windowDidResize:(NSNotification*)notification {
	[cocoaWindow update];
	NSRect viewFrame = cocoaWindow.contentView.frame;
	NSRect viewFrameBacking = [cocoaWindow.contentView convertRectToBacking:viewFrame];
	spruceWindow->width = viewFrameBacking.size.width;
	spruceWindow->height = viewFrameBacking.size.height;
}
@end

namespace spruce {
	void createMenu(NSString* appName) {
		NSMenu* bar = [[NSMenu alloc] init];
		[NSApp setMainMenu:bar];
		NSMenuItem* appMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
		NSMenu* appMenu = [[NSMenu alloc] init];
		[appMenuItem setSubmenu:appMenu];
		[appMenu addItemWithTitle:[NSString stringWithFormat:@"About %@", appName] action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];
		[appMenu addItem:[NSMenuItem separatorItem]];
		NSMenu* servicesMenu = [[NSMenu alloc] init];
		[NSApp setServicesMenu:servicesMenu];
		[[appMenu addItemWithTitle:@"Services" action:NULL keyEquivalent:@""] setSubmenu:servicesMenu];
		[servicesMenu release];
		[appMenu addItem:[NSMenuItem separatorItem]];
		[appMenu addItemWithTitle:[NSString stringWithFormat:@"Hide %@", appName] action:@selector(hide:) keyEquivalent:@"h"];
		[[appMenu addItemWithTitle:@"Hide Others" action:@selector(hideOtherApplications:) keyEquivalent:@"h"] setKeyEquivalentModifierMask:NSEventModifierFlagOption | NSEventModifierFlagCommand];
		[appMenu addItemWithTitle:@"Show All" action:@selector(unhideAllApplications:) keyEquivalent:@""];
		[appMenu addItem:[NSMenuItem separatorItem]];
		[appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit  %@", appName] action:@selector(terminate:) keyEquivalent:@"q"];
		NSMenuItem* windowMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
		[bar release];
		NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
		[NSApp setWindowsMenu:windowMenu];
		[windowMenuItem setSubmenu:windowMenu];
	}

	CocoaWindow::CocoaWindow(app::API api, uint16 width, uint16 height) : Window() {
		NSString* appName = @"spruce";
		createMenu(appName);
		NSUInteger windowStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;
		NSRect windowRect = NSMakeRect(0, 0, width, height);
		window = [[CocoaWindowObj alloc] initWithContentRect:windowRect styleMask:windowStyle backing:NSBackingStoreBuffered defer:NO];
		windowController = [[NSWindowController alloc] initWithWindow:window];
		[window setTitle:appName];
		if (api == app::OPENGL) {
			view = [[OpenGLView alloc] initWithFrame:windowRect window:this];
		} else if (api == app::METAL) {
			spruce::initDevice();
			view = [[MetalView alloc] initWithFrame:windowRect window:this];
			spruce::view = view;
		} else if (api == app::METAL2) {
		}
		[window setContentView:view];
		[window makeFirstResponder:view];
		if (api == app::OPENGL) {
			[view initContext];
		}
		spruce::Window* spruceWindow = this;
		delegate = [[WindowDelegate alloc] initWithWindow:spruceWindow cocoaWindow:window];
		[window setDelegate:delegate];
		[window makeKeyAndOrderFront: window];
		[NSApp activateIgnoringOtherApps:YES];
		[NSApp run];
	}

	CocoaWindow::~CocoaWindow() {
		[delegate dealloc];
		delegate = nullptr;
		[view release];
		view = nullptr;
		[windowController release];
		windowController = nullptr;
		[window release];
		window = nullptr;
	}

	void CocoaWindow::setTitle(string title) {
		NSString* nTitle = [NSString stringWithCString:title.c_str() encoding:[NSString defaultCStringEncoding]];
		[window setTitle:nTitle];
	}

	void CocoaWindow::setVisible(bool visible) {
		[window setOpaque:visible];
	}

	void CocoaWindow::setFullscreen(bool fullscreen) {
		if ([view isFullScreenMode]) {
			if (!fullscreen) {
				[view exitFullScreenMode];
			}
		} else {
			if (fullscreen) {
				[view enterFullScreenMode:[NSScreen mainScreen]];
			}
		}
	}

	void CocoaWindow::close() {
		[windowController close];
	}

	void CocoaWindow::setCursorMode(input::CursorMode mode) {
		this->cursorMode = mode;
		if (mode == input::HIDDEN || mode == input::DISABLED) {
			[NSCursor hide];
		} else {
			[NSCursor unhide];
		}
	}
}
