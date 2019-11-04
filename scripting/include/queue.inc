#if defined _queue_included
 #endinput
#endif
#define _queue_included

#include <adt_array>

methodmap Queue < Handle {
	public Queue(int size = 1, int start = 0) {
		return view_as<Queue>(CreateArray(size, start));
	}
	public int Push(any value) {
		return PushArrayCell(this, value);
	}
	public int PushString(const char[] value) {
		return PushArrayString(this, value);
	}
	public int PushArray(const any[] values, int size = -1) {
		return PushArrayArray(this, values, size);
	}
	public any Pop() {
		any value = GetArrayCell(this, 0);
		RemoveFromArray(this, 0);
		return value;
	}
	public int PopString(char[] buffer, int maxlength) {
		int charCount = GetArrayString(this, 0, buffer, maxlength);
		RemoveFromArray(this, 0);
		return charCount;
	}
	public int PopArray(any[] buffer, int size = -1) {
		int cellCount = GetArrayArray(this, 0, buffer, size);
		RemoveFromArray(this, 0);
		return cellCount;
	}
	public void Clear() {
		ClearArray(this);
	}
	public void Resize(int newsize) {
		ResizeArray(this, newsize);
	}
	public Queue Clone() {
		return view_as<Queue>(CloneArray(this));
	}
	property int Size {
		public get() { return GetArraySize(this); }
	}
}
