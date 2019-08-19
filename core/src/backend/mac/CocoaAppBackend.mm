#ifdef __APPLE__
#include <backend/mac/CocoaAppBackend.h>
#include <backend/mac/CocoaWindow.h>

@implementation CocoaApp
- (void) doNothing:(id) object {
}

- (void) quit {
	[[NSApp windows] makeObjectsPerformSelector:@selector(close)];
	[NSApp stop:nil];
}
@end

@implementation AppDelegate
- (void) applicationDidFinishLaunching:(NSNotification*)notification {
	[NSApp stop:nil];
	[NSApp activateIgnoringOtherApps:YES];
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)_app {
	return YES;
}
@end

namespace spruce {
	CocoaAppBackend::CocoaAppBackend() {
		[CocoaApp sharedApplication];
		[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
		[NSThread detachNewThreadSelector:@selector(doNothing:) toTarget:NSApp withObject:nil];
		delegate = [[AppDelegate alloc] init];
		[NSApp setDelegate:delegate];
		NSString* appName = @"spruce";
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
		[appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit  %@", appName] action:@selector(quit) keyEquivalent:@"q"];
		NSMenuItem* windowMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
		[bar release];
		NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
		[NSApp setWindowsMenu:windowMenu];
		[windowMenuItem setSubmenu:windowMenu];
		[NSApp run];
	}

	CocoaAppBackend::~CocoaAppBackend() {
		[delegate release];
		delegate = nullptr;
	}

	owner<Window> CocoaAppBackend::createWindow() {
		return new CocoaWindow();
	}

	void CocoaAppBackend::update() {
		while (true) {
			NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
			if (event != nullptr) {
				[NSApp sendEvent:event];
			}
			break;
		}
	}
}
#endif
