#ifndef HGUARD_AOSD_VIEW_NEWEDITIONSESSIONDIALOG_HPP__
#define HGUARD_AOSD_VIEW_NEWEDITIONSESSIONDIALOG_HPP__
#pragma once


namespace aosd
{
namespace view
{
	/** Dialog used to ask the user details on a new sequence to create. */
	class NewEditionSessionDialog
		: public QDialog
	{
		Q_OBJECT;
	public:

		NewEditionSessionDialog();
		~NewEditionSessionDialog();


	private slots:
			
	private:

		std::unique_ptr< Ui::NewEditionSessionDialog > m_ui;

		
	};

}
}


#endif
