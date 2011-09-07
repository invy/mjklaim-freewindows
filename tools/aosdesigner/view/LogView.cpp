#include "LogView.hpp"

#include <QTextEdit>

#include "utilcpp/Log.hpp"

namespace aosd
{

namespace view
{

	LogView::LogView()
		: m_text_area( new QTextEdit() )
	{
		setVisible( false );
		setWindowTitle(tr("Log"));
		setWidget( m_text_area.get() );

		util::register_log_output( [&]( const std::string& message ){ print_log( message ); }, 1 );
	}

	LogView::~LogView()
	{
		util::unregister_log_output( 1 );
	}

	void LogView::print_log( const std::string& message )
	{
		m_text_area->insertHtml( QString::fromStdString( message ) + "<br />" );
	}

}

}