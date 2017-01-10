/* Company :       Nequeo Pty Ltd, http://www.nequeo.com.au/
*  Copyright :     Copyright � Nequeo Pty Ltd 2015 http://www.nequeo.com.au/
*
*  File :          MediaPreviewForm.h
*  Purpose :       MediaPreviewForm class.
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

#pragma once

#ifndef _MEDIAPREVIEWFORM_H
#define _MEDIAPREVIEWFORM_H

#include "MediaGlobal.h"
#include "MediaPreview.h"

namespace Nequeo {
	namespace Media {
		namespace Foundation
		{
			/// <summary>
			/// Media preview window implementation. Preview a media resources from this window.
			/// </summary>
			class MediaPreviewForm : public CDialog
			{
				/// <summary>
				/// Media preview window enum.
				/// </summary>
				enum
				{
					/// <summary>
					/// The id of the media preview window.
					/// </summary>
					IDD = IDD_MEDIAPREVIEWCONTROL
				};

			public:
				/// <summary>
				/// Constructor for the current class.
				/// </summary>
				/// <param name="videoDevice">The media foundation device.</param>
				/// <param name="windowText">The widnow text.</param>
				/// <param name="pParent">The parent window.</param>
				EXPORT_NEQUEO_MEDIA_FOUNDATION_API MediaPreviewForm(IMFActivate* videoDevice, LPCTSTR windowText, CWnd* pParent = NULL);

				/// <summary>
				/// This destructor.
				/// </summary>
				EXPORT_NEQUEO_MEDIA_FOUNDATION_API ~MediaPreviewForm();

				/// <summary>
				/// On the windows as a modal.
				/// </summary>
				EXPORT_NEQUEO_MEDIA_FOUNDATION_API INT_PTR DoModal() override;

				/// <summary>
				/// Show the preview form modaless.
				/// </summary>
				EXPORT_NEQUEO_MEDIA_FOUNDATION_API BOOL ShowPreviewForm();

			protected:
				/// <summary>
				/// Data exchange.
				/// </summary>
				/// <param name="pDX">Data exchange instance.</param>
				virtual void DoDataExchange(CDataExchange* pDX);

			private:
				

			private:
				bool _disposed;
				BOOL _repaintClient;
				LPCTSTR _windowText;

				MediaPreview *_mediaPreview;
				CriticalSectionHandler	_critsec;
				IMFActivate* _videoDevice;
				HWND _hEvent;

				// Mapped controls.
				CToolTipCtrl* _toolTip;

			public:
				/// <summary>
				/// Declare the message map.
				/// </summary>
				DECLARE_MESSAGE_MAP()
				afx_msg void OnClose();
				afx_msg void OnDestroy();
				afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
				afx_msg void OnPaint();
				afx_msg void OnSize(UINT nType, int cx, int cy);
				afx_msg LRESULT OnNotifyState(WPARAM wParam, LPARAM lParam);
				afx_msg LRESULT OnNotifyError(WPARAM wParam, LPARAM lParam);
				afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
			};
		}
	}
}
#endif
