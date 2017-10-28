#include <backend/mac/CocoaWindow.h>
#include <backend/mac/opengl/OpenGLView.h>
#include <log.h>

@implementation CocoaApp
- (void) doNothing:(id) object {
}
@end

@implementation CocoaWindowObj
- (BOOL) canBecomeKeyWindow {
	return YES;
}

- (BOOL) canBecomeMainWindow {
	return YES;
}
@end

@implementation AppDelegate
- (void) applicationDidFinishLaunching:(NSNotification*)notification {
	[NSApp stop:nil];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)_app {
	return YES;
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
		[appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit %@", appName] action:@selector(terminate:) keyEquivalent:@"q"];
		NSMenuItem* windowMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
		[bar release];
		NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
		[NSApp setWindowsMenu:windowMenu];
		[windowMenuItem setSubmenu:windowMenu];
	}

	CocoaWindow::CocoaWindow(app::API api, uint16 width, uint16 height) : Window() {
		[CocoaApp sharedApplication];
		[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
		[NSThread detachNewThreadSelector:@selector(doNothing:) toTarget:NSApp withObject:nil];
		NSString* appName = @"spruce";
		createMenu(appName);
		NSUInteger windowStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;
		NSRect windowRect = NSMakeRect(0, 0, width, height);
		window = [[CocoaWindowObj alloc] initWithContentRect:windowRect styleMask:windowStyle backing:NSBackingStoreBuffered defer:NO];
		windowController = [[NSWindowController alloc] initWithWindow:window];
		[window setTitle:appName];
		if (api == app::OPENGL) {
			view = [[OpenGLView alloc] initWithFrame:windowRect];
		} else if (app::METAL) {
		} else if (app::METAL2) {
		}
		[window setContentView:view];
		[view initContext];
		[window makeKeyAndOrderFront: window];
		delegate = [[AppDelegate alloc] init];
		[NSApp setDelegate:delegate];
		[NSApp activateIgnoringOtherApps:YES];
		this->width = view.frame.size.width;
		this->height = view.frame.size.height;
		[NSApp run];
	}

	CocoaWindow::~CocoaWindow() {
		[view dealloc];
		view = nullptr;
		[windowController dealloc];
		windowController = nullptr;
		[window dealloc];
		window = nullptr;
		[delegate dealloc];
		delegate = nullptr;
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
}
