/* Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
*  Copyright :     Copyright � Nequeo Pty Ltd 2016 http://www.nequeo.com.au/
*
*  File :          WriteByteContainer.cpp
*  Purpose :       WriteByteContainer class.
*
*/

/*
Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "stdafx.h"

#include "WriteByteContainer.h"

#include <assert.h>

namespace Nequeo {
	namespace Media {
		namespace Foundation
		{
			/// <summary>
			/// Constructor for the current class.
			/// </summary>
			/// <param name="pb">Pointer to a buffer containing the data to write.</param>
			/// <param name="cb">Size of the buffer in bytes.</param>
			WriteByteContainer::WriteByteContainer(const BYTE *pb, ULONG cb) :
				_nRefCount(1),
				_pb(pb),
				_cb(cb),
				_pcbWritten(0),
				_writeCallback(NULL),
				_disposed(false)
			{

			}

			/// <summary>
			/// This destructor. Call release to cleanup resources.
			/// </summary>
			WriteByteContainer::~WriteByteContainer()
			{
				// If not disposed.
				if (!_disposed)
				{
					// Indicate that dispose has been called.
					_disposed = true;
				}
			}

			/// <summary>
			/// Add a new player ref item.
			/// </summary>
			/// <returns>The result.</returns>
			ULONG WriteByteContainer::AddRef()
			{
				// Increment the player ref count.
				return InterlockedIncrement(&_nRefCount);
			}

			/// <summary>
			/// Release this player resources.
			/// </summary>
			/// <returns>The result.</returns>
			ULONG WriteByteContainer::Release()
			{
				// Decrement the player ref count.
				ULONG uCount = InterlockedDecrement(&_nRefCount);

				// If released.
				if (uCount == 0)
				{
					// Delete this players resources.
					delete this;
				}

				// For thread safety, return a temporary variable.
				return uCount;
			}

			/// <summary>
			/// Get the player reference for the reference id.
			/// </summary>
			/// <param name="iid">The player reference id.</param>
			/// <param name="ppv">The current player reference.</param>
			/// <returns>The result of the operation.</returns>
			HRESULT WriteByteContainer::QueryInterface(REFIID iid, void** ppv)
			{
				// If null the return invalid pointer.
				if (!ppv)
				{
					return E_POINTER;
				}

				// Attach MediaCapture to the interface.
				static const QITAB qit[] =
				{
					QITABENT(WriteByteContainer, IUnknown),
					{ 0 },
				};
				return QISearch(this, qit, iid, ppv);
			}
		}
	}
}