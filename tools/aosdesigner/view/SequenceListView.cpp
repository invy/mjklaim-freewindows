#include "view/SequenceListView.hpp"

#include <QListView>

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/Sequence.hpp"

namespace aosd
{
namespace view
{

    SequenceListView::SequenceListView()
    {
        // configure the list
        setWindowTitle(tr("Sequences"));
        setSelectionMode( QAbstractItemView::SingleSelection );
        setEditTriggers( QAbstractItemView::NoEditTriggers ); // TODO : allow edition but then report the Sequence name change in the Project.Sequence.
        
        // the model informations
        setModel( &m_string_list );

        // connect to context signals
        auto& context = core::Context::instance();
        connect( &context, SIGNAL( project_open(const core::Project&)    ) , this, SLOT( on_project_open(const core::Project&)       ) );
        connect( &context, SIGNAL( project_changed(const core::Project&) ) , this, SLOT( on_project_changed(const core::Project&)    ) );
        connect( &context, SIGNAL( project_closed(const core::Project&)  ) , this, SLOT( on_project_closed(const core::Project&)     ) );

        // update the content if necessary
        if( context.is_project_open() )
        {
            read_sequences( context.current_project() );
        }

    }

    void SequenceListView::read_sequences( const core::Project& project )
    {
        QStringList sequence_names;
        
        project.foreach_sequence( [&]( const core::Sequence& sequence )
        {
            sequence_names << QString::fromStdString( sequence.name() );
        });

        m_string_list.setStringList( sequence_names );
    }

    void SequenceListView::clear()
    {
        m_string_list.setStringList(QStringList()); 
    }


    void SequenceListView::on_project_open( const core::Project& project )
    {
        read_sequences( project );
    }

    void SequenceListView::on_project_closed( const core::Project& project )
    {
        clear();
    }

    void SequenceListView::on_project_changed( const core::Project& project )
    {
        read_sequences( project );
    }

}
}