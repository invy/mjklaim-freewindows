#include "NewEditionSessionDialog.hpp"

#include "ui_NewEditionSessionDialog.h"

namespace aosd
{
namespace view
{

	NewEditionSessionDialog::NewEditionSessionDialog()
		: m_ui( new Ui::NewEditionSessionDialog() )
	{
		m_ui->setupUi( this );

		// interactions
		connect( m_ui->button_cancel			, SIGNAL( clicked() )					, this		, SLOT( reject() )				);
		connect( m_ui->button_create			, SIGNAL( clicked() )					, this		, SLOT( create_session() )		);
		//connect( m_ui->edit_name				, SIGNAL( textChanged(const QString&) )	, this		, SLOT( update_codename() )		);

		fill_session_selector();
	}

	NewEditionSessionDialog::~NewEditionSessionDialog()
	{

	}

	core::EditionSessionInfos NewEditionSessionDialog::infos() const
	{
		return core::EditionSessionInfos();
	}

	void NewEditionSessionDialog::create_session()
	{
		// TODO : check that the names are filled
		if( !m_ui->edit_name->text().isEmpty() 
		//&&	!m_ui->selector_sequence->
			)
		{
			// TODO : check that the location is valid
			// TODO : launch the creation of the project
			accept();
		}
		else
		{
			// TODO : notify the user?
		}

	}

	void NewEditionSessionDialog::fill_session_selector()
	{
		auto& selector = *m_ui->selector_sequence;

		
	}

}
}