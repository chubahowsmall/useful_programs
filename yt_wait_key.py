import os
from pyinotify import WatchManager, Notifier,ProcessEvent,IN_DELETE, IN_CREATE,IN_MODIFY
class EventHandler(ProcessEvent):
	#def process_IN_CREATE(self, event):
	#	print("Create file: %s " % os.path.join(event.path,event.name))

	#def process_IN_DELETE(self, event):
	#	print("Delete file: %s " % os.path.join(event.path,event.name))

	def process_IN_MODIFY(self, event):
		print("Modify file: %s " % os.path.join(event.path,event.name))

def FSMonitor(path='.'):
	wm = WatchManager() 
	mask = IN_DELETE | IN_CREATE |IN_MODIFY | IN_MODIFY
	notifier = Notifier(wm, EventHandler())
	wm.add_watch(path, mask,auto_add=True,rec=True)
	print('now starting monitor %s'%(path))

	while True:
		try:
			if notifier.check_events():
				notifier.read_events()
				print("key pressed")
				#notifier.stop()
				notifier.process_events()
				notifier.stop()
				break
		
		except KeyboardInterrupt:
			notifier.stop()
			print("exit")
			break

if __name__ == "__main__":
	FSMonitor('/sys/class/misc/cec_device/cec_key')
