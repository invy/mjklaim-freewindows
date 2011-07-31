#include "NewSequenceDialog.hpp"

#include "ui_NewSequenceDialog.h"

namespace aosd
{
namespace view
{
	NewSequenceDialog::NewSequenceDialog()
		: m_ui( new Ui::NewSequenceDialog() )
	{
		m_ui->setupUi( this );



	}

	NewSequenceDialog::~NewSequenceDialog()
	{

	}

	core::SequenceInfos NewSequenceDialog::sequence_infos()
	{
		core::SequenceInfos infos;

		return infos;
	}

}
}